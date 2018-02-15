import java.util.ArrayList;

public class Translator {

    private String translate(ArrayList<String> in){
        String out = "";
        int count = 0;
        if(in.size()==192){
            out=out+"["; //start
            for(int y = 0; y<12;y++){
                out=out+"["; //start of new row
                for(int x = 0; x<16; x++){
                    out=out+"["; //start of pixel
                    out=out+"\""+in.get(count).substring(0,2)+"\",\""+in.get(count).substring(2,4)+"\",\""+in.get(count).substring(4)+"\"";
                    out=out+"]"; //end of pixel
                    count++;
                }
                out=out+"]"; //end of row
            }
            out=out+"]"; //end


        }else{
            System.err.println("WRONG SIZE");
        }
        return out;
    }

    public static void main(String[] args){
        Parser parser = new Parser();
        ArrayList<String> input = parser.getParsed();
        Translator t = new Translator();
        System.out.println(t.translate(input));

    }
}
