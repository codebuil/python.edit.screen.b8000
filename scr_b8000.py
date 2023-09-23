import tkinter as tk
from tkinter import filedialog

def save_to_file():
    filename = filename_entry.get()
    x_value = int(x_entry.get())
    y_value =0
    # int(y_entry.get())

    input_text = input_text_area.get("1.0", "end-1c")  # Pega o texto da área de entrada

    # Função para formatar o texto com as cores
    def format_text(text):
        locs=ord('\\')
        z=ord('\0')
        bcolor=0
        ccolor=chr(7)
        ints=0
        strs=""
        print(f"{locs}")
        formatted_text =  ""
        for char in text:
            if ints > 0:
                if char == chr(ord('\\')):
                    formatted_text += f"{char}{ccolor}"
                    ints=0
                if char >= '0':
                    if char <= '9':
                        strs+=f"{char}"
                        ints=ints+1
                if char >= 'a':
                    if char <= 'f':
                        strs+=f"{char}"
                        ints=ints+1
                if char >= 'A':
                    if char <= 'F':
                        strs+=f"{char}"
                        ints=ints+1
                if ints > 2:
                    print(f"{char},{strs}")
                    ccolor=chr(int(strs,16))
                    strs=""
                    ints=0

            else:
                if char == chr(ord('\\')):
                    ints=1
                if char == '\n':
                    bcolor=0
                    for char in(bcolor,x_value):
                        formatted_text += f" {ccolor}"
                    formatted_text += f"\n" 

                
                else:
                     if char != '\r':
                         if ints==0:
                             bcolor=bcolor+1
                             formatted_text += f"{char}{ccolor}"
                             if bcolor >= x_value:
                                 bcolor=0
                                 formatted_text += f"\n"
        return formatted_text    
    formatted_text = format_text(input_text)            
    # Salva o texto formatado no arquivo
    with open(filename, 'w') as file:
        file.write("".join(formatted_text))
        

# Cria a janela principal
root = tk.Tk()
root.title("Janela Azul")
root.configure(bg="blue")

# Caixa de texto para o nome do arquivo
filename_label = tk.Label(root, text="Nome do Arquivo:")
filename_label.configure(bg="blue")
filename_label.pack()
filename_entry = tk.Entry(root)
filename_entry.pack()

# Caixa de texto para o valor x
x_label = tk.Label(root, text="Valor de x:")
x_label.configure(bg="blue")
x_label.pack()
x_entry = tk.Entry(root)
x_entry.pack()

# Caixa de texto para o valor y
y_label = tk.Label(root, text="Valor de y:")
y_label.configure(bg="blue")
y_label.pack()
y_entry = tk.Entry(root)
y_entry.pack()

# Área de texto para entrada de texto
input_text_label = tk.Label(root, text="Texto de Entrada:")
input_text_label.configure(bg="blue")
input_text_label.pack()
input_text_area = tk.Text(root, height=10, width=40)
input_text_area.configure(bg="blue")
input_text_area.pack()

# Botão para salvar o texto no arquivo
save_button = tk.Button(root, text="Salvar", command=save_to_file)
save_button.configure(bg="blue")
save_button.pack()

root.mainloop()
