import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.util.*;


//i metodi sono static perch่ devono essere richiamati dal main che ่ static
public class Esercizio {

	public static void main(String[] args) {
		query0(); //stampare 10 libri
		query1(); //Contare tutti i libri CYBERPUNK
		query2(); //Lista dei titoli dei Libri CYBERPUNK o FANTASY
		query3(); //Somma dei costi di tutti i libri
		query4(); //Somma in dollari dei costi di tutti i libri (1 = 1.10$)
		query5(); //Stampa tutti i libri con prezzo compreso tra 10 e 15
		query6(); //Titolo del Libro meno caro (ma a partire da 12)
		query7(); //Stampa la lista dei libri ordinati per prezzo
		query8(); //Stampare conteggio vendite per ogni libro
		query9(); //Stampare i libri per categoria
		query10(); //creare una lista di libri fantasy da harry potter 1 al 7, tutti da 15 euro
		query11(); //sfruttando il metodo precedente, ottenere la lista di libri e mescolarla in ordine casuale
		//data una lista di libri, stampare il primo che ha un prezzo maggiore del precedente (metodo lambda)
		//data una lista di libri, stampare il primo che ha un prezzo maggiore del precedente (metodo )

	}
	
	public static void query0() {
		System.out.println("Query 0");
		
		Stream.generate(Libro::gen)
				.limit(10)
				.forEach(System.out::println);
	}
	
	public static void query1() {
		System.out.println("Query 1");
		
		long n=Stream.generate(Libro::gen)
					 .limit(10)
					 .filter(x->x.getCategoria()==Libro.Categoria.CYBERPUNK)
					 .count();
		System.out.println("i libri CYBERPUNK sono: "+n);
	}
	
	public static void query2() {
		System.out.println("Query 2");
		
		List<String> list=Stream.generate(Libro::gen)
			  .limit(10)
			  .filter(x->x.getCategoria()==Libro.Categoria.CYBERPUNK || x.getCategoria()==Libro.Categoria.FANTASY)
			  .map(x->x.getTitolo())
			  .collect(Collectors.toList());
		System.out.println(list);
	}
	
	public static void query3() {
		System.out.println("Query 3");
		
		List<Libro> list=Stream.generate(Libro::gen)
				.limit(5)
				.collect(Collectors.toList());
		
		long n=list.stream()
					 .map(x->x.getPrezzo())
					 .reduce(0, Integer::sum);
		System.out.println("somma costi : "+n);
		
		long n2=list.stream()
				 .mapToInt(x->x.getPrezzo())
				 .sum();
	System.out.println("somma costi : "+n2);
	}
	
	public static void query4() {
		System.out.println("Query 4");
		
		double n=Stream.generate(Libro::gen)
				 		.limit(5)
				 		.map(x->x.getPrezzo()*1.12)
				 		.reduce(0d, Double::sum);
	System.out.print("somma costi $: ");  
	System.out.format("%.2f\n",n);	//limitare cifre dopo virgola system.out.format %.2f
	}
	
	public static void query5() {
		System.out.println("Query 5");
		
		Stream.generate(Libro::gen)
			  .limit(10)
			  .filter(x->x.getPrezzo()>=10)
			  .filter(x->x.getPrezzo()<=15)
			  .forEach(System.out::println);
	}
	
	public static void query6() {
		System.out.println("Query 6");
		
		Optional<Libro> l=Stream.generate(Libro::gen)
								.limit(10)
								.filter(x->x.getPrezzo()>=12)
								.min(Comparator.comparing(x->x.getPrezzo()));
		
		if(l.isPresent())
			System.out.println("min: "+l.get().getTitolo());
		else
			System.out.println("Libro non presente");

	}
	
	public static void query7() {
		System.out.println("Query 7");
		
		Stream.generate(Libro::gen)
				.limit(10)
				.sorted(Comparator.comparing(x->x.getPrezzo()))
				.forEach(System.out::println);
	}
	
	public static void query8() {
		System.out.println("Query 8");
		
		List<Libro> list=Stream.generate(Libro::gen)
				.limit(10)
				.collect(Collectors.toList());
		
		list.stream()
		.map(x->x.getTitolo())
		.distinct()
		.peek(x->System.out.print("Titolo: "+x+" Conteggio: "))
		.forEach(x->System.out.println(
					list.stream()
					.filter(t->t.getTitolo().equals(x))
					.count()));
	}
	
	public static void query9() {
		System.out.println("Query 9");
		
		List<Libro> list=Stream.generate(Libro::gen)
				.limit(6)
				.distinct()
				.collect(Collectors.toList());
		
		list.stream()
		.map(x->x.getCategoria())
		.distinct()
		.peek(x->System.out.println("Categoria: "+x))
		.forEach(x->list.stream()
					.filter(t->t.getCategoria().equals(x))
					.map(t->t.getTitolo())
					.forEach(t->System.out.println(" - "+t)));
		

	}
	
	public static List<Libro> query10() {
		System.out.println("Query 10");
		
		List<Libro> list=IntStream.rangeClosed(1,7)
							.mapToObj(x->new Libro("Harry Potter "+x,Libro.Categoria.FANTASY,15))
							.collect(Collectors.toList());
		list.forEach(System.out::println);
		return list;
	}
	
	public static void query11() {
		System.out.println("Query 11");
		
		List<Libro> list=query10();
		
		Stream.generate(Math::random)
			.map(d->(int)(d*list.size()))
			.distinct()
			.limit(list.size())
			.map(i->list.get(i))
			.forEach(System.out::println);
		
		Stream.generate(Math::random)
				.peek(x->System.out.println(x))
				.map(d->(int)(d*5))
				.distinct()
				.limit(5)
				.forEach(System.out::println);
	}
	
	public static void query12() {
		
	}
}
