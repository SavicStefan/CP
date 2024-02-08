for((i = 1; ; i++)); do
	echo $i
	./rand > in
	./sol < in > out1
	./stu < in > out2
	diff -w out1 out2 || break
done