import<string>;
import<iostream>;
import <filesystem>;
import<vector>;
import <fstream>;

namespace {
std::vector<std::string> split(const std::string& pStr, char pDelimiter) {
  std::vector<std::string> out;
  out.emplace_back();
  for(char c : pStr) {
    if(c == pDelimiter) {
      out.emplace_back();
    } else {
      out.back().push_back(c);
    }
  }
  return out;
}

std::string join(const std::vector<std::string>& pStrs, const std::string& pDelimiter) {
  std::string out;
  for(unsigned int idx = 0; idx != pStrs.size(); ++idx) {
    out += pStrs[idx];
    if(idx != pStrs.size() - 1) {
      out += pDelimiter;
    }
  }
  return out;
}

void makeDir(const std::string& pDir) {
  std::filesystem::create_directory(pDir);
  //std::cout << "Making Directory " << pDir << std::endl;
}

void writeFile(const std::string& pFile, const std::string& pContents) {
  //std::cout << "Writing File" << pFile << "\n";
  //std::cout << "With contents \n" << pContents << std::endl;
   std::ofstream file(pFile, std::ofstream::out | std::ofstream::trunc);
   file << pContents;
   file.close();
}
}

int main(int argc, const char** argv) {
  if(argc != 2) {
    std::cout << "Please supply a module name as the first and only argument." << std::endl;
    return 0;
  }
  std::string module(argv[1]);
  std::vector<std::string> moduleSplitName(split(module, '.'));
  if(moduleSplitName.size() < 2) {
    std::cout << "Invalid module name." << std::endl;
    return 0;
  }
  if(moduleSplitName[0] != std::string("ezs")) {
    std::cout << "Invalid module name." << std::endl;
    return 0;
  }
  for(const std::string& str : moduleSplitName) {
    if(str.empty()) {
      std::cout << "Invalid module name." << std::endl;
      return 0;
    }
  }
  std::vector<std::string> moduleQualifiers(moduleSplitName.begin() + 1, moduleSplitName.end());
  std::string rootDir = "/home/dev/EzS";
  std::string moduleDir = rootDir + "/src/" + join(moduleQualifiers, "/");
  std::string name = moduleSplitName.back();
  makeDir(moduleDir);
  std::string moduleMKFile = moduleDir + "/" + moduleSplitName.back() + ".mk";
  std::string MKFileContents =
      "MODULE_DIR := $(GET_CURRENT_DIR)\n"
      "MODULES += "+ module +" test." + module +"\n"
      + module + "_INTERFACE_FILE := $(MODULE_DIR)/" + moduleSplitName.back() +".hxx\n"
      + module + "_INTERFACE_DEPS := \n"
      "test." + module + "_IMPLEMENTATION_FILE := $(MODULE_DIR)/t" + moduleSplitName.back() +".cpp\n"
      "test." + module + "_IMPLEMENTATION_DEPS := "+ module +"\n";
  writeFile(moduleMKFile, MKFileContents);

  std::string nameSpace = join(std::vector<std::string>(moduleSplitName.begin() + 1, moduleSplitName.end() - 1), "::");

  std::string moduleHXXFile = moduleDir + "/" + moduleSplitName.back() + ".hxx";
  std::string moduleHXXFileContents = "export module " + module +
                                      ";\n"
                                      "export\n"
                                      "namespace ezs::"
                                      + nameSpace
                                      + " {\n"
                                      "class " + name + " final {\npublic:\n"
    "constexpr " + name + "() noexcept = delete;\n"
    "constexpr " + name + "(const "+name+"&) noexcept = delete;\n"
    "constexpr " + name + "("+name+"&&) noexcept = delete;\n"
    "constexpr " + name + "& operator=(const "+name+"&) & noexcept = delete;\n"
    "constexpr " + name + "& operator=("+name+"&&) & noexcept = delete;\n"
    "constexpr ~" + name + "() noexcept = delete;\n"
                                      "};\n} // namespace ";
  writeFile(moduleHXXFile, moduleHXXFileContents);

  std::string moduleTestFile = moduleDir +"/t"+moduleSplitName.back() + ".cpp";
  std::string moduleTestFileContents =
      "import " + module + ";\n"
      "using namespace ezs::" + nameSpace + ";\n"
      "namespace {\n\n} // namespace \n";
  writeFile(moduleTestFile, moduleTestFileContents);
  return 0;
}
