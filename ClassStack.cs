using System;
class TestStack
{
	static void Main()
	{
		Stack stack = new Stack(10);
		Console.WriteLine("Input Your Command : ");
		Console.WriteLine("_______________________");
		Console.WriteLine("push A");
		Console.WriteLine(" --> to push 'A' to Stack");
		Console.WriteLine("pop");
		Console.WriteLine(" --> to pop item from Stack");
		Console.WriteLine("isEmpty");
		Console.WriteLine("isFull");
		Console.WriteLine("Top");
		Console.WriteLine(" --> getValue Top of Stack SP");
		Console.WriteLine("Exit");
		Console.WriteLine(" --> to Exit");
		Console.WriteLine("_______________________");

		char myItem;

		do {
			string command = Console.ReadLine();
			bool recieve_stack_boolean = false;
			if (command == "Exit") {
				break;
			}
			if (command == "pop") {
				myItem = stack.pop();
			}
			else if (command.Split(' ')[0] == "push") {
				recieve_stack_boolean = stack.push(Convert.ToChar(command.Split(' ')[1]));
			}
			else if (command == "isEmpty") {
				recieve_stack_boolean = stack.isEmpty();
			}
			else if (command == "isFull") {
				recieve_stack_boolean = stack.isFull();
			}
			else if (command == "top") {
				Console.WriteLine(stack.getTop());
			}
		}
		while (true);
	}
}

class Stack
{
	private int max;
	private int top;
	private char[] stackItem;

	public Stack(int max) {
		this.max = max;
		stackItem = new char [max];
		for (int i = 0; i < max; i++) {
			this.stackItem[i] = '\0';
		}
		this.top = 0;
	}

	public bool push(char item) {
		if (this.top < this.max) {
			this.stackItem[this.top++] = item;
			Console.WriteLine("push {0}", item);
			return true;
		}
		else {
			Console.WriteLine("StackOverFlow");
			return false;
		}
	}

	public char pop() {
		if (this.top > 0) {
			char item = this.stackItem[--this.top];
			Console.WriteLine("pop {0}", item);
			return item;
		}
		else {
			Console.WriteLine("StackUnderFlow");
			return '\0';
		}
	}

	public bool isEmpty() {
		if (this.top == 0) {
			Console.WriteLine("Stack is Empty");
			return true;
		}
		else {
			Console.WriteLine("Stack isn't Empty");
			return false;
		}
	}

	public bool isFull() {
		if (this.top == this.max) {
			Console.WriteLine("Stack is Full");
			return true;
		}
		else {
			Console.WriteLine("Stack isn't Full");
			return false;
		}
	}

	public int getTop() {
		return this.top;
	}

}
