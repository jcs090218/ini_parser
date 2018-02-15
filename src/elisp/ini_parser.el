;; ========================================================================
;; $File: ini_parser.el $
;; $Date: 2018-02-12 03:10:32 $
;; $Revision: $
;; $Creator: Jen-Chieh Shen $
;; $Notice: See LICENSE.txt for modification and distribution information
;;                   Copyright © 2018 by Shen, Jen-Chieh $
;; ========================================================================



(defun get-string-from-file (filePath)
  "Return filePath's file content.
TOPIC(jenchieh): Elisp: Read File Content as String or List of Lines
URL(jenchieh): http://ergoemacs.org/emacs/elisp_read_file_content.html"
  (with-temp-buffer
    (insert-file-contents filePath)
    (buffer-string)))

(defun jcs-parse-ini (filePath)
  "Parse a .ini file.
FILEPATH : .ini file to parse."

  (let ((tmp-ini (get-string-from-file filePath))
        (tmp-ini-list '())
        (tmp-pair-list nil)
        (tmp-keyword "")
        (tmp-value "")
        (count 0))
    (setq tmp-ini (split-string tmp-ini "\n"))

    (dolist (tmp-line tmp-ini)
      ;; check not comment.
      (when (not (string-match-p "#" tmp-line))
        ;; Split it.
        (setq tmp-pair-list (split-string tmp-line "="))

        ;; Assign to temporary variables.
        (setq tmp-keyword (nth 0 tmp-pair-list))
        (setq tmp-value (nth 1 tmp-pair-list))

        ;; Check empty value.
        (when (and (not (string= tmp-keyword ""))
                   (not (equal tmp-value nil)))
          (add-to-list 'tmp-ini-list tmp-keyword)
          (add-to-list 'tmp-ini-list tmp-value)))
      (setq count (1+ count)))

    ;; Reverse list once.
    (setq tmp-ini-list (reverse tmp-ini-list))

    ;; return list.
    tmp-ini-list))
