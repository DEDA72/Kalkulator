#include <iostream>
#include <stack>
using namespace std;
struct leks
{
	char typ;
	double value;
};
bool math(stack<leks>& Stack_n, stack <leks>& Stack_o, leks& i_0)
{
	double a, b, c;
	a = Stack_n.top().value;
	Stack_n.pop();
	switch (Stack_o.top().typ)
	{
	case '+':b = Stack_n.top().value;
		Stack_n.pop();
		c = a + b;
		i_0.typ = '0';
		i_0.value = c;
		Stack_n.push(i_0);
		Stack_o.pop();
		break;
	case '-':b = Stack_n.top().value;
		Stack_n.pop();
		c = b - a;
		i_0.typ = '0';
		i_0.value = c;
		Stack_n.push(i_0);
		Stack_o.pop();
		break;
	case '*':b = Stack_n.top().value;
		Stack_n.pop();
		c = a * b;
		i_0.typ = '0';
		i_0.value = c;
		Stack_n.push(i_0);
		Stack_o.pop();
		break;
	case '/':b = Stack_n.top().value;
		if (a == 0) { cout << "error! you cant use / to 0!!!"; return false; }
		Stack_n.pop();
		c = b / a;
		i_0.typ = '0';
		i_0.value = c;
		Stack_n.push(i_0);
		Stack_o.pop();
		break;
	default:cout << "error!";
	}
	return true;
}
int rang(char ch)
{
	if (ch == '+' || ch == '-')return 1;
	if (ch == '*' || ch == '/')return 2;
	else return 0;
}
int main()
{
	cout << "Input math problem(without ())\n";
	char ch;
	double value;
	stack <leks> Stack_n;
	stack <leks> Stack_o;
	leks i_0;
	bool falg = 1;
	while (1) {
		ch = cin.peek();
		if (ch == '\n')break;
		if (ch >= '0' && ch <= '9' || ch == '-' || falg == 1)
		{
			cin >> value;
			i_0.typ = '0';
			i_0.value = value;
			Stack_n.push(i_0);
			falg = 0;
			continue;
		}
		if (ch == '+' || ch == '-' || falg == 0 || ch == '*' || ch == '/')
			if (Stack_o.size() == 0) {
				i_0.typ = ch;
				i_0.value = 0;
				Stack_o.push(i_0);
				cin.ignore();
				continue;
			}
		if (Stack_o.size() != 0 && rang(ch) > rang(Stack_o.top().typ))
		{
			i_0.typ = ch;
			i_0.value = 0;
			Stack_o.push(i_0);
			cin.ignore();
			continue;

		}
		if (Stack_o.size() != 0 && rang(ch) <= rang(Stack_o.top().typ))
		{
			if (math(Stack_n, Stack_o, i_0) == false) { return 0; }
		}
		continue;
		if (ch == '(')
		{
			i_0.typ = ch;
			i_0.value = 0;
			Stack_o.push(i_0);
			cin.ignore();
			continue;
		}
	}
	if (ch == ')')
	{
		while (Stack_o.top().typ != '(')
		{
			while (Stack_o.size() != 0) {
				if (math(Stack_n, Stack_o, i_0) == false) { return 0; }
				else continue;
			}
			Stack_o.pop();
			cin.ignore();
			continue;
		}
	}
	;
	while (Stack_o.size() != 0) {
		if (math(Stack_n, Stack_o, i_0) == false) { return 0; }
		else continue;
	}
	cout << "Resultat = " << Stack_n.top().value << endl;
	cout << "\n\nMade by Kyryl Nazarets\n";
	return 0;
}