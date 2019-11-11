import java.util.List;

public class Plotter {
	private List<Integer> xValues;
	
	Plotter(List<Integer> values) {
		xValues=values;
	}
	
	public void plot(Function f) {
		for(int num : xValues)
			System.out.println(num+"  -->  "+f.get(num));
		
		System.out.println("---------------");
	}
	
	public void somma() {
		System.out.println("Somma: "+xValues.stream().reduce(0, (acc,x)->acc+x));
		// xValues.stream().reduce(0f, Float::sum);
	}
}
