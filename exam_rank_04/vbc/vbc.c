#include "vbc.h"

node *new_node(node n)
{
	node *ret = calloc(1, sizeof(node));
	if (!ret)
		exit(1);
	*ret = n;
	return (ret);
}

void destroy_tree(node *n)
{
	if (!n)
		return;
	if (n->type != VAL)
	{
		destroy_tree(n->l);
		destroy_tree(n->r);
	}
	free(n);
}

void unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
}

int accept(char **s, char c)
{
	if (**s == c)
	{
		(*s)++;
		return (1);
	}
	return (0);
}

int expect(char **s, char c)
{
	if (accept(s, c))
		return (1);
	unexpected(**s);
	exit(1);
}

node *parse_expr_internal(char **s);

node *parse_factor(char **s)
{
	if (accept(s, '('))
	{
		node *ret = parse_expr_internal(s);
		expect(s, ')');
		return (ret);
	}
	else if (isdigit(**s))
	{
		node *ret = new_node((node){VAL, **s - '0', NULL, NULL});
		(*s)++;
		return (ret);
	}
	unexpected(**s);
	exit(1);
}

node *parse_term(char **s)
{
	node *left = parse_factor(s);
	while (accept(s, '*'))
	{
		node *right = parse_factor(s);
		left = new_node((node){MULTI, 0, left, right});
	}
	return left;
}

node *parse_expr_internal(char **s)
{
	node *left = parse_term(s);
	while (accept(s, '+'))
	{
		node *right = parse_term(s);
		left = new_node((node){ADD, 0, left, right});
	}
	return left;
}

node *parse_expr(char *s)
{
	char *ptr = s;
	if (!s || *s == '\0')
		return (NULL);
	node *ret = parse_expr_internal(&ptr);
	if (*ptr != '\0')
	{
		unexpected(*ptr);
		destroy_tree(ret);
		exit(1);
	}
	return (ret);
}

int eval_tree(node *tree)
{
	if (tree->type == ADD)
		return (eval_tree(tree->l) + eval_tree(tree->r));
	if (tree->type == MULTI)
		return (eval_tree(tree->l) * eval_tree(tree->r));
	return (tree->val);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	node *tree = parse_expr(argv[1]);
	if (!tree)
		return (1);
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
	return (0);
}