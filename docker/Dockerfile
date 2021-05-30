FROM debian:unstable AS debian-updated
RUN echo 'APT::Acquire::Retries "10";' > /etc/apt/apt.conf.d/80-retries
RUN DEBIAN_FRONTEND=noninteractive apt update && apt upgrade -y

FROM debian-updated AS download-llvm-project
RUN DEBIAN_FRONTEND=noninteractive apt install -y --no-install-recommends --fix-missing git ca-certificates
WORKDIR /llvm-project
RUN git clone --progress --depth 1 --single-branch --branch release/12.x https://github.com/llvm/llvm-project.git .
COPY source_location_patch.diff source_location_patch.diff
RUN git apply --whitespace=fix source_location_patch.diff

FROM debian-updated AS build-llvm-project-core-deps
RUN DEBIAN_FRONTEND=noninteractive apt install -y  --no-install-recommends --fix-missing cmake ninja-build python3
COPY --from=download-llvm-project /llvm-project /llvm-project

FROM build-llvm-project-core-deps AS build-llvm-project-bootstrap
RUN DEBIAN_FRONTEND=noninteractive apt install -y --no-install-recommends --fix-missing clang lld libc++-dev libc++abi-dev
WORKDIR /llvm-project/build-bootstrap
RUN cmake \
-DCMAKE_C_COMPILER=clang \
-DCMAKE_CXX_COMPILER=clang++ \
-DCMAKE_INSTALL_PREFIX=/llvm-project/install-bootstrap \
-DCMAKE_BUILD_TYPE=Release \
-DLLVM_ENABLE_LTO=ON \
-DLLVM_USE_LINKER=lld \
-DLLVM_ENABLE_LIBCXX=ON \
-DLLVM_INSTALL_BINUTILS_SYMLINKS=ON \
-DLLVM_TARGETS_TO_BUILD="X86" \
-DLLVM_ENABLE_PROJECTS="clang;lld;libcxx;libcxxabi;pstl" \
-DLLVM_ENABLE_MODULES=ON \
-G Ninja ../llvm
RUN cmake --build . --target install-clang install-clang-resource-headers install-lld install-cxx install-cxxabi install-llvm-ar install-llvm-nm

FROM build-llvm-project-core-deps AS build-llvm-project-release-deps
RUN DEBIAN_FRONTEND=noninteractive apt install -y  --no-install-recommends --fix-missing python3-distutils libedit-dev libz3-dev libatomic1 libgcc-10-dev
COPY --from=build-llvm-project-bootstrap /llvm-project/install-bootstrap /llvm-project/install-bootstrap

FROM build-llvm-project-release-deps AS build-llvm-project-release
WORKDIR /llvm-project/build-release
RUN cmake \
-DCMAKE_C_COMPILER=/llvm-project/install-bootstrap/bin/clang \
-DCMAKE_CXX_COMPILER=/llvm-project/install-bootstrap/bin/clang++ \
-DCMAKE_CXX_FLAGS="-stdlib=libc++" \
-DCMAKE_EXE_LINKER_FLAGS="--ld-path=/llvm-project/install-bootstrap/bin/ld.lld" \
-DCMAKE_INSTALL_PREFIX=/llvm-project/install-release \
-DCMAKE_BUILD_TYPE=Release \
-DLLVM_ENABLE_LTO=ON \
-DLLVM_ENABLE_LIBCXX=ON \
-DLLVM_ENABLE_LLD=ON \
-DLLVM_TARGETS_TO_BUILD=all \
-DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra;compiler-rt;libcxx;libcxxabi;lld;lldb;pstl" \
-DLLVM_ENABLE_Z3_SOLVER=ON \
-DLLVM_ENABLE_MODULES=ON \
-DCOMPILER_RT_BUILD_LIBFUZZER=OFF \
-G Ninja ../llvm
RUN export LD_LIBRARY_PATH=/llvm-project/install-bootstrap/lib && cmake --build . --target install

FROM build-llvm-project-core-deps AS build-llvm-project-libcxx-deps
RUN DEBIAN_FRONTEND=noninteractive apt install -y  --no-install-recommends --fix-missing libatomic1 libgcc-10-dev libz3-dev libc6-dev
COPY --from=build-llvm-project-release /llvm-project/install-release /llvm-project/install-release

FROM build-llvm-project-libcxx-deps AS build-llvm-project-debug-libcxx
WORKDIR /llvm-project/build-debug-libcxx
RUN cmake \
-DCMAKE_C_COMPILER=/llvm-project/install-release/bin/clang \
-DCMAKE_CXX_COMPILER=/llvm-project/install-release/bin/clang++ \
-DCMAKE_CXX_FLAGS="-stdlib=libc++" \
-DCMAKE_EXE_LINKER_FLAGS="--ld-path=/llvm-project/install-release/bin/ld.lld" \
-DLLVM_ENABLE_LLD=ON \
-DCMAKE_INSTALL_PREFIX=/llvm-project/install-debug-libcxx \
-DLLVM_ENABLE_LIBCXX=ON \
-DLLVM_ENABLE_MODULES=ON \
-DCMAKE_BUILD_TYPE=Debug \
-DLLVM_TARGETS_TO_BUILD=all \
-DLLVM_ENABLE_PROJECTS="libcxx;libcxxabi;pstl" \
-G Ninja ../llvm
RUN cmake --build . --target install-cxx install-cxxabi install-pstl

FROM build-llvm-project-libcxx-deps AS build-llvm-project-msan-libcxx
COPY --from=build-llvm-project-release /llvm-project/install-release /llvm-project/install-release
WORKDIR /llvm-project/build-msan-libcxx
RUN cmake \
-DCMAKE_C_COMPILER=/llvm-project/install-release/bin/clang \
-DCMAKE_CXX_COMPILER=/llvm-project/install-release/bin/clang++ \
-DCMAKE_CXX_FLAGS="-stdlib=libc++" \
-DCMAKE_EXE_LINKER_FLAGS="--ld-path=/llvm-project/install-release/bin/ld.lld" \
-DLLVM_ENABLE_LLD=ON \
-DCMAKE_INSTALL_PREFIX=/llvm-project/install-msan-libcxx \
-DLLVM_ENABLE_LIBCXX=ON \
-DLLVM_ENABLE_MODULES=ON \
-DCMAKE_BUILD_TYPE=Debug \
-DLLVM_TARGETS_TO_BUILD=all \
-DLLVM_ENABLE_PROJECTS="libcxx;libcxxabi;pstl" \
-DLLVM_USE_SANITIZER=MemoryWithOrigins \
-G Ninja ../llvm
RUN cmake --build . --target install-cxx install-cxxabi install-pstl

FROM debian:unstable as p4v-install
WORKDIR /p4v-build
RUN wget https://www.perforce.com/downloads/perforce/r21.1/bin.linux26x86_64/p4v.tgz
RUN tar xvzf p4v.tgz /p4v

FROM debian-updated
COPY --from=build-llvm-project-msan-libcxx /llvm-project/install-msan-libcxx /llvm-project/msan-libcxx
COPY --from=build-llvm-project-debug-libcxx /llvm-project/install-debug-libcxx /llvm-project/debug-libcxx
COPY --from=build-llvm-project-release /llvm-project/install-release /llvm-project/release

COPY --from=p4v-install /p4v /p4v
RUN ln -s /p4v/bin/p4merge /usr/bin/p4merge

WORKDIR /usr/local/bin
COPY external_merge_tool external_merge_tool
RUN chmod a+x external_merge_tool
COPY external_diff_tool external_diff_tool
RUN chmod a+x external_diff_tool

WORKDIR /
RUN echo 'APT::Acquire::Retries "5";' > /etc/apt/apt.conf.d/80-retries
RUN apt update && \
    DEBIAN_FRONTEND=noninteractive apt upgrade -y && \
    DEBIAN_FRONTEND=noninteractive apt install -y --no-install-recommends --fix-missing \
    xfce4 tigervnc-standalone-server less procps nano sudo openssl openssh-server supervisor man dbus-x11 emacs chromium xfce4-terminal \
    htop chromium make ca-certificates git libc6-dev libboost-dev
RUN useradd --create-home --shell /bin/bash --groups sudo -p `openssl passwd -1 default` dev
COPY ./supervisord.conf /etc/supervisor/conf.d/supervisord.conf
RUN mkdir /var/run/sshd

USER dev
WORKDIR /home/dev
COPY --chown=dev:dev ./vncpasswd .vnc/passwd
RUN chmod 600 .vnc/passwd
COPY --chown=dev:dev ./xstartup .vnc/xstartup
RUN chmod 744 .vnc/xstartup

COPY --chown=dev:dev docker_gitconfig .gitconfig

COPY --chown=dev:dev ./init.el .emacs.d/init.el

USER root
WORKDIR /
CMD ["/usr/bin/supervisord"]