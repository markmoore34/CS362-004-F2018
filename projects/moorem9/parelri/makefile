CFLAGS = -Wall -Wextra -fpic -coverage -lm -std=c99

default: unittestresults

unittestresults: randomtestcard1.c randomtestadventurer.c randomtestcard2.c unittest1.c unittest2.c dominion.c rngs.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
#

	echo "TEST Result for running Dominion tests:" >> unittestresults.out
	echo "\n\trandomtestcard1.c:" >> unittestresults.out
	gcc -o randomtest1 -g dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtest1 >> unittestresults.out
	echo "FINISHED ./RANDOMTEST1" >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\trandomtestadventurer.c:" >> unittestresults.out
	gcc -o randomtestadventurer -g dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestAdventurer >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\trandomtest2.c:" >> unittestresults.out
	gcc -o randomtest2 -g dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\tunittest1.c:" >> unittestresults.out
	gcc -o unittest1 -g dominion.c rngs.c unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\tunittest2.c:" >> unittestresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\tunittest3.c:" >> unittestresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\tunittest4.c:" >> unittestresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\tcardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 dominion.c rngs.c cardtest1.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\tcardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\n\tcardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 dominion.c rngs.c cardtest3.c $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

	echo "\ncardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 dominion.c rngs.c cardtest4.c $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c -b >> unittestresults.out

clean:
	rm unittestresults.out

cleanall:
	rm unittestresults.out *.gcda *.gcno *.gcov randomtest1 randomtestadventurer randomtest2 unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

#
