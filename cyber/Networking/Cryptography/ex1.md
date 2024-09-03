Generated a key with "gpg --full-generate-key"

Created a file example.txt, example1.txt, example2.txt

Encrypted with "gpg --output example.txt.gpg --encrypt example.txt"

Signed a file with compression "gpg --output example1.txt.sig --sign --compress-level 9 example1.txt"

Verified "gpg --verify example2.txt.sig"

Signed a file without compression "gpg --output example2.txt.sig --sign example2.txt"

Verified with "gpg --verify example3.txt.sig example3.txt"

