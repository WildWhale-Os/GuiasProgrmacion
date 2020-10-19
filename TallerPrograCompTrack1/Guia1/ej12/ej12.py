prefijos = {}
telefonos = []
tiempo = []
costoTotal = []
costoMin = []
telfSinPref = []
localidades = []
salida = ''
linea = input()
while linea != "000000":
    dato = linea.split(" ", 1)
    demas = dato[1].split("$")
    prefijos[dato[0]] = [demas[0], int(demas[1])/100]
    linea = input()

linea = input()
i = 0

lenTel = 0
lenTelSin = 0
lenLocalidad = 0
lencostoMin = 0
lenCostoTotal = 0
lenTiempo = 0

while linea != "#":
    llamada = linea.split(" ", 1)
    tiempo.append(int(llamada[1].strip()))
    telefonos.append(llamada[0].strip())
    mapeadado = False
    for j in prefijos:
        if telefonos[i].startswith(j):
            telfSinPref.append(telefonos[i][len(j):])
            localidades.append(prefijos[j][0])
            costoMin.append(prefijos[j][1])
            costoTotal.append(tiempo[i] * costoMin[i])
            mapeadado = True
            break
    if telefonos[i].startswith('0') and not mapeadado:
        localidades.append("Unknown")
        costoTotal.append(-1.00)
        costoMin.append('')
        telfSinPref.append('')
        mapeadado = True
    elif not mapeadado:
        localidades.append("Local")
        telfSinPref.append(telefonos[i])
        costoMin.append(0.00)
        costoTotal.append(tiempo[i] * costoMin[i])

    if len(telefonos[i]) > lenTel:
        lenTel = len(telefonos[i])
    if len(telfSinPref[i]) > lenTelSin:
        lenTelSin = len(telfSinPref[i])
    if len(localidades[i]) > lenLocalidad:
        lenLocalidad = len(localidades[i])
    if(isinstance(costoMin[i], int)):
        string = '{:.2f}'.format(costoMin[i])
        if len(string) > lencostoMin:
            lencostoMin = len(string)
    else:
        if len(costoMin[i]) > lencostoMin:
            lencostoMin = len(costoMin[i])
    string = '{:.2f}'.format(costoTotal[i])
    if len(string) > lenCostoTotal:
        lenCostoTotal = len(string)
    string = '{}'.format(tiempo[i])
    if len(string) > lenTiempo:
        lenTiempo = len(string)
    i += 1

lenTel += 1
lencostoMin += 1
lenCostoTotal += 1
for i in range(len(telefonos)):
    salida = f"{telefonos[i]:<{lenTel}}{localidades[i]:<{lenLocalidad}}{telfSinPref[i]:>{lenTelSin}}{tiempo[i]:>{lenTiempo}}{costoMin[i]:>{lencostoMin}.2f}{costoTotal[i]:>{lenCostoTotal}.2f}"
    print(salida)
