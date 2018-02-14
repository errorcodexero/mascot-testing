import java.io.*;
import java.lang.reflect.Array;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

/**
 * Class for importing a full string of the html image file
 *
 * @author CaptainGeo
 * @date 2-12-2018
 */
public class Importer {

    /**
     * Gets the file name (ex test.html) from the user, finds the full file path
     * @return filepath
     */
    private String getFilePath(){
        System.out.println("Insert name of html file to import (must be in the mascot-testing directory):");
        Scanner in = new Scanner(System.in);
        String fileNameIn = in.nextLine();
        System.out.println("Input file: " + fileNameIn);
        String filePath = System.getProperty("user.dir") + "/" + fileNameIn;
        return filePath;
    }

    /**
     * Finds file length (in lines)
     * @param filePath
     * @return file length
     */
    private int getFileLength(String filePath){
        int lineNumber = 0;
        try {
            FileReader fr = new FileReader(filePath);
            LineNumberReader lnr = new LineNumberReader(fr);
            while(lnr.readLine() != null){
                lineNumber++;
            }
            System.out.println("Number of Lines: " + lineNumber);
            lnr.close();
            return lineNumber;
        }
        catch(IOException e){
           // e.printStackTrace();
        }
        return lineNumber;
    }

    /**
     * Adds entire file contents into a string
     * @return file contents
     */
    private String readFile(){
        try{
            byte[] encoded = Files.readAllBytes(Paths.get(getFilePath()));
            return new String(encoded, Charset.defaultCharset());
        }catch(IOException ioe){
            System.out.println("ERROR READING FILE/FILE PATH");
        }
        return "";
    }

    /**
     * Getter for string with file text
     * @return file string
     */
    public String getFile(){
        return readFile();
    }

    /**
     * Importer constructor
     */
    public Importer(){
    }

    public static void main(String[] args){
        Importer a = new Importer();
        System.out.println("Insert name of html file to import (must be in the mascot-testing directory):");
        Scanner in = new Scanner(System.in);
        String fileNameIn = in.nextLine();
        System.out.println("Input file: " + fileNameIn);
        System.out.println(System.getProperty("user.dir"));
        //String filePath=a.getFilePath(fileNameIn);

        //a.readFile(filePath,Charset.defaultCharset());

    }
}
