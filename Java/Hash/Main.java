import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

//ler cada linha
//pegar o primeiro item e colocar npo array;
//cada indice tem um array que coloca os 

public class Main {

    public static int[] GetLinks(Item[] Data, int Value)
    {
        for(int i = 0; i < Data.length; ++i)
        {
            if(Data[i].Value == Value)
            {
                return Data[i].Links;
            }
        }
        return null;
    }
    public static void main(String args[]){

        String caminhoArquivo = "./txt/desafio1.txt"; // 1 = true, 2 = false, 3 = true, 4 = false, 5 = true
        Item[] Dados;
        try {
            // Cria um objeto FileReader para ler o arquivo
            FileReader arquivoReader = new FileReader(caminhoArquivo);

            // Cria um objeto BufferedReader para ler linhas do arquivo
            BufferedReader leitor = new BufferedReader(arquivoReader);
            int N = 0;
            while(leitor.readLine() != null)
            {
                ++N;
            }
            leitor.close();
            arquivoReader = new FileReader(caminhoArquivo);
            leitor = new BufferedReader(arquivoReader);

            // Variável para armazenar cada linha lida do arquivo
            String linha;

            // Lê cada linha do arquivo até encontrar o final do arquivo
            Dados = new Item[N];
            N = 0;
            while((linha = leitor.readLine()) != null)
            {
                linha = linha.replaceAll(" ", "");
                String[] partes = linha.split("[>]");

                Dados[N] = new Item();
                Dados[N].Value = Integer.parseInt(partes[0]);

                if(partes.length == 1)
                {
                    //Dados[N].Links = null;
                    ++N;
                    continue;
                }

                String[] filhos = partes[1].split("[,]");
                int[] Links = new int[filhos.length];

                for(int i = 0; i < filhos.length; ++i)
                {
                    Links[i] = Integer.parseInt(filhos[i]);
                }
                Dados[N].Links = Links;
                ++N;
            }
            // Fecha o BufferedReader após a leitura
            leitor.close();
        } catch (IOException e) {
            // Trata exceções de leitura de arquivo, se ocorrerem
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
            return;
        }

        Queue<Integer> Fila = new Queue<Integer>();
        boolean LoopFound = false;
        for(int i = 0; i < Dados.length; ++i)
        {
            Hash Caminhos = new Hash(256);
            Fila.Enqueue(Dados[i].Value);
            while(Fila.Size() > 0)
            {
                int N = Fila.Dequeue();
                if(Caminhos.Search(N))
                {
                    LoopFound = true;
                    break;
                }
                Caminhos.Add(N);
                int[] Links = GetLinks(Dados, N);
                if(Links == null){continue;}
                for(int j = 0; j < Links.length; ++j)
                {
                    Fila.Enqueue(Links[j]);
                }
            }
        }
        System.out.println(LoopFound);
    }
}

