Updated makefile to be able to compile the project.
Upon compilation tester program revealed various issues with my code and also my libft functions.

All problems pointed out by Francinette resolved.
These were:
Segfault due to accessing non allocated space in my libft functions: ft_strdup, ft_itoa, ft_bitoa and ft_utoa. Used calloc instead of malloc to resolve the problem

Edge cases for s% and p% conversions - printing (null) and (nil) for empty ponters

These made the code longer so had to separate both of these conversion cases' functions in separate files, edit ft_printf.h header file and Makefile
