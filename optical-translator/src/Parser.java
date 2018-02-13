public class Parser {
    public static void main(String[] args){
        Importer importer = new Importer();
        String raw = importer.getFile();
        System.out.println(raw);
    }
}
