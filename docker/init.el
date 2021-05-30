;; List packages to install
(setq package-list '(lsp-mode lsp-ui company flycheck company clang-format clang-format+))

;; Initialize MELPA repo
(require 'package)
(add-to-list 'package-archives '("melpa" . "https://melpa.org/packages/"))
(package-initialize)

;; Update repo package list
(unless package-archive-contents
  (package-refresh-contents))

;; Install all packages
(dolist (package package-list)
   (unless (package-installed-p package)
     (package-install package)))

;; Setup lsp, flycheck, company
(require 'lsp-mode)
(require 'company)
(require 'flycheck)
(setq lsp-clients-clangd-executable "/llvm-project/release/bin/clangd")
(setq lsp-log-io t)
(add-hook 'c-mode-hook #'lsp)
(add-hook 'c++-mode-hook #'lsp)

;; Setup clang-format
(require 'clang-format)
(setq clang-format-style "file")

(require 'clang-format+)
(add-hook 'c-mode-common-hook #'clang-format+-mode)

;; Redirect backup files
(setq backup-directory-alist `(("." . "~/.emacs-saves")))
(setq backup-by-copying t)
(setq delete-old-versions t
  kept-new-versions 6
  kept-old-versions 2
  version-control t)
