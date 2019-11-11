//ctrl+shift+f identazione automatica

public class Libro {
	static enum Categoria {
		FANTASY, CYBERPUNK, THRILLER
	}

	private String titolo;
	private Categoria categoria;
	private int prezzo;

	Libro(String titolo, Categoria categoria, int prezzo) {
		this.titolo = titolo;
		this.categoria = categoria;
		this.prezzo = prezzo;
	}

	private static Libro[] prodPool = new Libro[] {
			new Libro("Leviathan", Categoria.FANTASY, 20),
			new Libro("Trono di Spade", Categoria.FANTASY, 40),
			new Libro("Signore degli Anelli", Categoria.FANTASY, 25),

			new Libro("Necromante", Categoria.CYBERPUNK, 15),
			new Libro("Monnalisa Cyberpunk", Categoria.CYBERPUNK, 12),
			new Libro("Mirrorshades", Categoria.CYBERPUNK, 10),

			new Libro("Profondo blu", Categoria.THRILLER, 8),
			new Libro("Invasion", Categoria.THRILLER, 12),
			new Libro("La Torre Nera", Categoria.THRILLER, 18)
		};

	public static Libro gen() {
		int i = (int) (Math.random() * prodPool.length);
		return prodPool[i];
	}

	@Override
	public String toString() {
		return "titolo=" + titolo + ", categoria=" + categoria + ", prezzo=" + prezzo + "€]";
	}

	public String getTitolo() {
		return titolo;
	}

	public int getPrezzo() {
		return prezzo;
	}

	public Categoria getCategoria() {
		return categoria;
	}
	
}
