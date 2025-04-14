Everything works as expected now.
Makefile compiles Libft and adds it to the project.

ft_printf can be called and handles the following conversions:
cdipsuxX%

No bonuses included.

Changes made:
Makefile updated - compiles project successfully.

Upon compilation tester program revealed various issues with the code and also my libft functions.

All problems pointed out by Francinette resolved.
These were:
Segfault due to accessing non allocated space in my libft functions: ft_strdup, ft_itoa, ft_bitoa and ft_utoa.
Updated those functions to use calloc instead of malloc to resolve the problem.

Edge cases for s% and p% conversions - printing (null) and (nil) for empty ponters.

These changes made the code longer than 25 lines allowed per function.
Separate functions and files created for these two conversions.
ft_printf.h header file and Makefile edited to accomodate changes.
