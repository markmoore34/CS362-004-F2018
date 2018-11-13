CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults

unittestresults: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.c rngs.c

	echo "Result for running Dominion tests:" >> unittestresults.out
	echo "randomtestcard1.c:" >> unittestresults.out
	gcc -o randomtest1 -g dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "Result for running Dominion tests:" >> unittestresults.out
	echo "randomtestadventurer.c:" >> unittestresults.out
	gcc -o randomtestadventurer -g dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestAdventurer >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "Result for running Dominion tests:" >> unittestresults.out
	echo "randomtest2.c:" >> unittestresults.out
	gcc -o randomtest2 -g dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

clean:
	rm unittestresults.out
cleanall:
	rm unittestresults.out randomtest1 randomtest2 randomtestadventurer *.gcda *.gcno *.gcov
