foo = $(bar) 
bar = $(ugh)
ugh = Huh?

.PHONY: echo
echo: ; @echo $(foo)
ugh = Yeah!
echo: ;

