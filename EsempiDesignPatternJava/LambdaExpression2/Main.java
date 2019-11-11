import java.util.*;
import java.util.function.*;
import java.util.stream.*;

public class Main {

	public static void main(String[] args) {
		Plotter p=new Plotter(List.of(1,2,3,4));
		
		p.plot(x->Math.pow(x,2));
		p.plot(x->Math.sqrt(x));
		p.plot(Math::cos);
		p.plot(Math::sin);
		p.somma();
		List<Integer> s1=Stream.of("abc","ciao","sunny","ab")
								.map(v->v.length())
								.sorted(Comparator.reverseOrder()) //ordine decrescente
								.collect(Collectors.toList());
		//.sorted() crescente di default
		
		// non serve il ciclo for per stampare valori di una lista
		System.out.println("Length(): "+s1);
		
		List<Integer> s2=List.of(1,2,3,4,-2,-3);
		
		Predicate<Integer> positive= x -> x>=0;
		System.out.println("con predicate: "+s2.stream().filter(positive).collect(Collectors.toList()));
		
		Optional<Integer> massimo=s2.stream().max(Integer::compare); //.max(Comparator.compare(x->x.getEta()))
		System.out.println("max: "+massimo.get());
		
		Optional<Integer> minimo=s2.stream().min(Integer::compare);
		System.out.println("min: "+minimo.get());
	}
}