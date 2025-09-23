# pipex

[Ir a Español](#español) | [Go to English](#english)

---

## 🏳️‍⚡ English

### What is this project?

**pipex** is a project for learning about process management, piping, and file descriptors in UNIX/Linux environments. It is usually assigned in programming schools such as 42 or similar as an exercise to implement a simplified version of shell pipelines.

### What does it do?

This program replicates the behavior of the shell command pipeline (`|`) for a set of two commands, handling input and output file redirection. For example, it allows you to run commands like:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Which will execute:

```bash
< infile cmd1 | cmd2 > outfile
```

- It takes an input file, processes it through `cmd1`, pipes the output to `cmd2`, and writes the final result to `outfile`.

### How to use

1. **Compile the project**  
   Run `make` or compile the source files:

   ```bash
   make
   ```

2. **Run pipex**

   ```bash
   ./pipex infile "command1 [args]" "command2 [args]" outfile
   ```

   - `infile`: The input file to read from.
   - `command1 [args]`: The first command to execute.
   - `command2 [args]`: The second command to execute.
   - `outfile`: The output file to write the result to.

3. **Example**

   ```bash
   ./pipex file1.txt "grep hello" "wc -l" result.txt
   ```

   This will count the number of lines containing "hello" in `file1.txt` and write the count to `result.txt`.

---

## 🇪🇸 Español

### ¿Para qué es este proyecto?

**pipex** es un proyecto destinado a aprender sobre la gestión de procesos, uso de pipes y descriptores de archivos en entornos UNIX/Linux. Suele ser un ejercicio habitual en escuelas de programación como 42 para implementar una versión simplificada de los pipelines de la shell.

### ¿Qué hace?

Este programa replica el funcionamiento del pipe (`|`) de la shell para dos comandos, gestionando la redirección de archivos de entrada y salida. Por ejemplo, te permite ejecutar comandos como:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Lo cual ejecuta:

```bash
< infile cmd1 | cmd2 > outfile
```

- Toma un archivo de entrada, lo procesa con `cmd1`, pasa la salida por un pipe a `cmd2` y escribe el resultado final en `outfile`.

### ¿Cómo se usa?

1. **Compilar el proyecto**  
   Ejecuta `make` o compila los archivos fuente:

   ```bash
   make
   ```

2. **Utilizar pipex**

   ```bash
   ./pipex infile "comando1 [args]" "comando2 [args]" outfile
   ```

   - `infile`: Archivo de entrada.
   - `comando1 [args]`: Primer comando a ejecutar.
   - `comando2 [args]`: Segundo comando a ejecutar.
   - `outfile`: Archivo de salida.

3. **Ejemplo**

   ```bash
   ./pipex archivo.txt "grep hola" "wc -l" resultado.txt
   ```

   Esto contará las líneas que contienen "hola" en `archivo.txt` y escribirá el conteo en `resultado.txt`.

---

[Ir a Español](#español) | [Go to English](#english)
