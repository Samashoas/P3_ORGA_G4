# P3_ORGA_G4
# TIKALPARK
| Integrante | Carnet | Porcentaje |
|:----------|:------:|--------:|
| Francisco Gerardo Castillo Sagastume        |202300653    |20% |
|Alvaro Gabriel Ceballos Gil| 202300673| 20%|
|Juan Pablo Samayoa Ruiz| 202109705| 20%|
|Kenneth Issai Aquino Ortiz| 202100678|20%|
|Brandon Orlando Seijas Morales| 202010035|20%|

## Introducción
El presente reporte tiene como finalidad documentar el desarrollo y aplicación de conocimientos teóricos y prácticos adquiridos en el curso, específicamente en el área de Electrónica Digital. A lo largo del proyecto, se ha trabajado en la construcción de un sistema que integra tanto lógica combinacional como lógica secuencial, con el objetivo de consolidar habilidades esenciales en el diseño de circuitos digitales.

El enfoque del trabajo estuvo orientado a la optimización del diseño, buscando siempre reducir la cantidad de dispositivos utilizados sin comprometer la funcionalidad. Finalmente, este proyecto representa un espacio para fortalecer la capacidad de resolver problemas reales mediante la aplicación de conceptos de Electrónica Digital, y permite al estudiante explorar de forma práctica los múltiples usos de la lógica secuencial en sistemas electrónicos
## Descripcción del problema
El hotel “Grand Tikal Futura” esta pensando en realizar una torre de parqueos similar al que 
tiene su competencia de Miraflores, por lo cual se le solicito a usted y su equipo de 
organización computacional para realizar un prototipo de dicha torre de parqueos el cual se 
dispondrá de 3 niveles para dicho prototipo, así mismo se le solicita los siguientes 
requerimientos: 

* En la entrada del parqueo tenga una garita automática en el cual se pueda extraer 
un ticket, posteriormente se levante la barra para que pueda pasar el vehículo.
* Deberá llevar el conteo de vehículos que hay en la torre, así como el conteo de carros 
que hay por nivel.
* cada nivel tendrá un amento de estacionamientos empezando con el primer nivel el 
cual tendrá 3 estacionamientos, el segundo nivel 4 y el tercero 5 estacionamientos.
* Se debe de tomar en cuenta que al momento que cuando un nivel se quede sin 
estacionamientos deberá de indicar que pase al siguiente nivel y cuando ya no haya 
estacionamientos se cierre la torre y encienda una luz roja.
* El vehículo tendrá 20 segundos para poder pasar por la garita posteriormente la 
garita bajará la barra para que no pase dicho vehículo.
* Para salir el vehículo deberá de ingresar la contraseña ubicada en el ticket por la 
garita el cual si es correcto subirá la barra para que pueda retirarse, si fuera 
incorrecta deberá de cerrar el parqueo y activar la alarma de robo la cual se 
desactivara por medio de la garita de salida.

## Procesos teorícos

### Puente H
El puente H es un circuito electrónico fundamental para el control de motores de corriente directa (DC), ya que permite cambiar la dirección de giro del motor mediante el control del flujo de corriente. Este circuito es ampliamente utilizado en robótica, mecatrónica y sistemas de control.

1. Funcionamiento basico
   * Se usan cuatro transistores: Q1, Q2, Q3 y Q4
   * El motor se conecta en el centro.
   * Para girar en un sentido: activar Q1 y Q4.
   * Para girar en sentido opuesto: activar Q2 y Q3.
   * Nunca se deben activar Q1 y Q2 o Q3 y Q4 al mismo tiempo (cortocircuito).
2. Componentes clave
   * Transistores/MOSFETs
   * Diodos de protección
   * Fuente de alimentación adecuada.
   * Microcontrolador o switches para control.
3. Montaje y pruebas
   * Se diseña el circuito tipo "H" y se monta en protoboard.
   * Se puede simular en software antes de armar.
   * Se controla con señales para cambiar la dirección del motor.

### Talanquera
El sensor ultrasónico (como el HC-SR04) permite medir distancias mediante ondas sonoras. Es útil en sistemas de detección de obstáculos o control de proximidad.

1. Principio de funcionamiento
   ```bash
   Distancia = (tiempo * velocidad del sonido)/2
   ```
2. Conexión al arduino
   * VCC -> 5V
   * GND -> GND
   * TRIG -> Pin digital
   * ECHO -> Pin digital
3. Uso practico
   Con la distancia calculada, se pueden activar otros componentes (como LEDs, servos o alarmas) según la cercanía de un objeto.

### Teclado y contraseña
Este sistema permite ingresar una contraseña mediante botones físicos, compararla con una contraseña predefinida (almacenada con flip-flops), y validar si es correcta o no.

1. Entrada del usuario
   * Se utilizan botones fisicos
   * Cada botón representa un dígito binario o un valor específico de la contraseña.
2. Resgistro de entradas
   * A medida que el usuario presiona los botones, los valores se cargan en un registro temporal hecho con flip-flops tipo D o T.
   * Los flip-flops almacenan la secuencia ingresada mientras se completa la contraseña.
3. Contraseña almacenada
   * La contraseña correcta está “quemada” (cableada) mediante flip-flops o puertas lógicas.
   * Estos valores no cambian, y sirven como referencia para la comparación.
4. Comparación
   * Se utiliza lógica combinacional (XOR, AND) para comparar bit a bit la entrada del usuario con la contraseña almacenada.
   * Si todos los bits coinciden, el sistema activa una señal de “acceso correcto”.
5. Salida del sistema
   * Si la comparación es exitosa: No se activa una led verde que indica que la contraseña es correcta
   * Si no coincide: Se actia una led roja y se mandá señal a un puente H el cual activa un servo motor

### Contador sincronico y asincronico
1. Contador sincronico
   * Todos los flip-flops reciben la señal de reloj al mismo tiempo.
   * Las transiciones son más rápidas y precisas.
   * Requiere lógica adicional para determinar cuándo cada flip-flop debe cambiar de estado.
+ Caracterisiticas: 
  * Se usan puertas AND/OR junto a los flip-flops.
  * Mejor rendimiento en sistemas digitales precisos.
2. Contador Asíncronico
  * También llamado contador en cascada.
  * Solo el primer flip-flop recibe la señal de reloj externa.
  * Los siguientes flip-flops toman como reloj la salida del anterior.
  * Es más simple, pero más lento, ya que el cambio se propaga de uno en uno.
+ Caracteristicas: 
  * Uso de flip-flops tipo T o JK configurados para toggle.
  * Fácil de construir, pero presenta retardos acumulativos.
3. Aplicaciones y Comparación
  * Sincrónicos: preferidos en sistemas rápidos y complejos (como microcontroladores o FPGAs).
  * Asincrónicos: útiles en sistemas simples o donde la velocidad no es crítica.
### Mapas de Karnaugh
![Tabla de verdad](https://github.com/Samashoas/P3_ORGA_G4/blob/main/Imagenes%20Reporte%20P3/Tabla%20de%20verdad.jpg?raw=true)
![Tabla de estados](https://github.com/Samashoas/P3_ORGA_G4/blob/main/Imagenes%20Reporte%20P3/Tabla%20de%20estado.jpg?raw=true)
![Tabla de excitación](https://github.com/Samashoas/P3_ORGA_G4/blob/main/Imagenes%20Reporte%20P3/Tabla%20de%20excitacion.jpg?raw=true)
![Mapas de Karnaugh](https://github.com/Samashoas/P3_ORGA_G4/blob/main/Imagenes%20Reporte%20P3/Untitled-2025-02-28-2006.png?raw=true)

### Diagramas de los diseños
![Puente H](https://github.com/Samashoas/P3_ORGA_G4/blob/main/Diagramas%20proteus/Puente%20H.jpg?raw=true)
![Teclado y contraseña](https://github.com/Samashoas/P3_ORGA_G4/blob/main/Diagramas%20proteus/Teclado.jpg?raw=true)
![Contador](https://github.com/Samashoas/P3_ORGA_G4/blob/main/Diagramas%20proteus/Contador.jpg?raw=true)
