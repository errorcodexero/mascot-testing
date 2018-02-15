import java.util.ArrayList;

/**
 * Class for parsing hex color codes out of the input string
 *
 * @author CaptainGeo
 * @date 2-15-2018
 * @version 1.0
 */
public class Parser {
    /**
     * Method to parse the full input string into an ArrayList of strings
     * @param raw input string (NOTE: must be formatted correctly, this is done with a 16x12 html image file. Easily exported through GIMP)
     * @return ArrayList of hex values (should have 192 individual strings, each with 6 hex digits)
     */
    private ArrayList<String> parseRaw(String raw){
        ArrayList<String> out = new ArrayList<>();
        int lengthRaw = raw.length();

        for(int i=0; i<lengthRaw; i++){
            if(raw.substring(i,i+1).equals("#")){
                if(lengthRaw>i+8){
                    out.add(raw.substring(i+1,i+7));
                }else{
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
