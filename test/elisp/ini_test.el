;; ========================================================================
;; $File: ini_test.el $
;; $Date: 2018-02-12 03:14:14 $
;; $Revision: $
;; $Creator: Jen-Chieh Shen $
;; $Notice: See LICENSE.txt for modification and distribution information
;;                   Copyright © 2018 by Shen, Jen-Chieh $
;; ========================================================================

;; Include the file.
(load-file "../src/elisp/ini_parser.el")

(defun test-run ()
  "Main function to test ini parser."

  (let ((ini-data '()))
    (setq ini-data (jcs-parse-ini "../test.ini"))

    (message "Version: %s" (nth 1 ini-data))
    (message "Name: %s" (nth 3 ini-data))
    (message "Age: %s" (nth 5 ini-data))
    (message "Email: %s" (nth 7 ini-data))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Output:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Version: 1.0.0
;; Name: dummy_name
;; Age: 18
;; Email: hello_world@aldes.com
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
