
public class Adapter extends Adaptee implements Target {  //CLASS ADAPTER
	
	Adapter(int i) {
		super(i);
	}
	
	public void request() {
		specificRequest();
	}
	
}

/*
public class Adapter implements Target {    //OBJECT ADAPTER
	Adaptee a;
	
	public void request() {
		if(a==null)
			a=new Adaptee();
		a.specificRequest();
	}
}
*/