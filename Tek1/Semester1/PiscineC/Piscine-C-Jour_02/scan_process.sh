echo 'Which process to watch ? (enter real name)'
read m
j=$(pgrep "$m")
echo "How much time you want program to scan ? (1 = 00.01 sec)"
read k 
top -p "$j" -n "$k" -d 00.01
