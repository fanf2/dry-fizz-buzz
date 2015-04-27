#define predicates(p) \
	p(Fizz, i % 3 == 0) \
	p(Buzz, i % 5 == 0)

#define pred_fun(name, test) static bool name(int i) { return test; }
#define pred_ent(name, test) { name, #name },

predicates(pred_fun)

pred ptbl[] = {
	predicates(pred_ent)
};

#define ptbl_end (ptbl + sizeof(ptbl)/sizeof(*ptbl))
