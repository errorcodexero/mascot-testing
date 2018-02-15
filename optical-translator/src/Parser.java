import java.util.ArrayList;

public class Parser {

    private ArrayList<String> parseRaw(String raw){
        ArrayList<String> out = new ArrayList<String>();
        //ArrayList<String> out;


        int lengthRaw = raw.length();

        for(int i=0; i<lengthRaw; i++){
            if(raw.substring(i,i+1).equals("#")){
                if(lengthRaw>i+8){
                    out.add(raw.substring(i+1,i+7));
                }
                else{
                    break;
                }
            }
        }

        if(out.isEmpty()){
            out.add("ERR");
        }
        return out;
    }

    public static void main(String[] args){
        Importer importer = new Importer();
        String raw = importer.getFile();
        System.out.println("String Length: "+raw.length());
        Parser a = new Parser();
        System.out.println(a.parseRaw(raw));
    }
}
