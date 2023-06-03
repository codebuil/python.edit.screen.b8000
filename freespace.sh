printf "\ec\e[44;30m\n"
printf "utility to make a free disk file, put a free disk file size in megabytes, afther the image is load into memory delete it in memory\n"
read megas
dd if=/dev/zero of=free.nul  bs=1M count=$megas
