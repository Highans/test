This is one half of an experimental platform for delivering updates using git
it hooks on pre-commit and puts the crc32, size, and path of the git files
into a file named filelist. The client is then supposed to download filelist,
compare crc's and download the changed files.