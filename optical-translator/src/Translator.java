package src;

import java.util.ArrayList;

/**
 *
 */

public class Translator {

    private String translate(ArrayList<String> in){
        String out = "";
        int count = 0;
        if(in.size()==192){
            out=out+"[\n\t["; //start
            for(int y = 0; y<12; y++){
                out=out+"\n\t\t["; //start of new row
                for(int x = 0; x<15; x++){
                    out=out+"["; //start of pixel
                    out=out+"\""+in.get(count).substring(0,2)+"\",\""+in.get(count).substring(2,4)+"\",\""+in.get(count).substring(4)+"\"";
                    out=out+"], "; //end of pixel
                    count++;
                }
                out=out+"["; //start of pixel
                out=out+"\""+in.get(count).substring(0,2)+"\",\""+in.get(count).substring(2,4)+"\",\""+in.get(count).substring(4)+"\"";
                out=out+"]"; //end of pixel
                count++;
                if(count!=192){
                    out=out+"],";
                }else{
                    out = out + "]"; //end of row
                }
            }

            out=out+"\n\t]\n]"; //end


        }else{
            System.err.println("WRONG SIZE: "+in.size());
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
