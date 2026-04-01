exs=$(find . -type d -name ex*)
for ex in $exs; do
	make -C $ex fclean
done
