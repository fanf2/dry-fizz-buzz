#define predicate(name, test) \
	static bool name(int i) { return test; } \
	pred predicate_##name __attribute__((section("predicate"))) \
		= { name, #name }

predicate(Fizz, i % 3 == 0);
predicate(Buzz, i % 5 == 0);

extern pred __start_predicate[], __stop_predicate[];

#define ptbl     __start_predicate
#define ptbl_end __stop_predicate
