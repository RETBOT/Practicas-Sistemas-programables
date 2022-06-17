# Descripción
## Si la posición del servomotor no coincide con el ángulo correspondiente, es porque el ancho del pulso que maneja la librería no coincide con los del servo, para esto es necesario indicarle el ancho de pulso min(para 0°) y el máximo (para 180°), la única modificación sería en la siguiente línea:
### myservo.attach(9,900,2100); // asignamos el pin 9 al servo, 900->0° y 2100->180°

![Practicas 10 Servomotor]()
