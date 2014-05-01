package proto;

public class A {
	public int a=65;
	public static B newB() { return new B(); }
	public static class B {
		public int b=66;
	}
}