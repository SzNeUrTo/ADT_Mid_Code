using System;
class TestStack
{
	static void Main()
	{
		Stack stack = new Stack(10);
		char myItem = '\0';
		stack.Pop(ref myItem);

	}
}

class Stack
{
	private int max;
	private int Top;
	private char[] StackItem;

	public Stack(int max) 
	{
		this.max = max;
		StackItem = new char [max];
		for (int i = 0; i < max; i++)
		{
			this.StackItem[i] = '\0';
		}
		this.Top = 0;
	}
	public bool Push(char item)
	{
		if (Top < max)
		{
			this.StackItem[Top++] = item;
			Console.WriteLine("Push {0}", item);
			return true;
		}
		else
		{
			Console.WriteLine("StackOverFlow");
			return false;
		}
	}
	public bool Pop(ref char item)
	{
		if (Top > 0)
		{
			item = this.StackItem[--Top];
			Console.WriteLine("Pop {0}", item);
			return true;
		}
		else
		{
			Console.WriteLine("StackUnderFlow");
			return false;
		}
	}
	public bool isEmpty()
	{
		if (Top == 0)
		{
			Console.WriteLine("Stack is Empty");
			return true;
		}
		else
		{
			Console.WriteLine("Stack isn't Empty");
			return false;
		}
	}
	public bool isFull()
	{
		if (Top == max)
		{
			Console.WriteLine("Stack is Full");
			return true;
		}
		else
		{
			Console.WriteLine("Stack isn't Full");
			return false;
		}
	}

}
