## ✅ Modos de abertura de arquivos em C

| Modo  | Significado                  | O que faz?                                                     |
|------- |---------------------------- |--------------------------------------------------------------- |
| "r"    | Read (Leitura)              | Abre um arquivo existente para **leitura**. Erro se não existir. |
| "w"    | Write (Escrita)             | Cria um arquivo vazio ou **apaga** se já existir, e abre para **escrita**. |
| "a"    | Append (Anexar)             | Abre ou cria um arquivo para **escrever no final** (sem apagar o conteúdo). |
| "r+"   | Read + Write                | Abre um arquivo existente para **leitura e escrita**. Erro se não existir. |
| "w+"   | Write + Read                | Cria um arquivo vazio ou **apaga** se já existir, e abre para **leitura e escrita**. |
| "a+"   | Append + Read               | Abre ou cria um arquivo para **leitura e escrita**, mas **escreve sempre no final**. |

---

## ✅ Modos para arquivos binários

| Modo   | Significado                  | O que faz?                                                     |
|-------  |---------------------------- |--------------------------------------------------------------- |
| "rb"    | Read Binary                 | Leitura de um arquivo **binário**.                             |
| "wb"    | Write Binary                | Criação/reescrita de um arquivo **binário**.                   |
| "ab"    | Append Binary               | Acrescenta dados no final de um arquivo **binário**.           |
| "r+b"   | Read + Write Binary         | Leitura e escrita em arquivo binário existente.                |
| "w+b"   | Write + Read Binary         | Cria ou apaga arquivo binário, depois lê e escreve.            |
| "a+b"   | Append + Read Binary        | Lê e escreve, sempre acrescentando no final.                   |

---

## Dicas rápidas:

- **Texto** → use `"r"`, `"w"`, `"a"` ou combinados com `"+"`.
- **Binário** → adicione `"b"`: `"rb"`, `"wb"`, etc.
- **Cuidado**: modos com `"w"` **apagam o conteúdo** do arquivo.

