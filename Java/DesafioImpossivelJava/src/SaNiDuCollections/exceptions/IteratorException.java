package SaNiDuCollections.exceptions;

public class IteratorException extends Exception
{
    public IteratorException()
    {
        super("Iterator tento acessar elemento inexistente");
    }
}