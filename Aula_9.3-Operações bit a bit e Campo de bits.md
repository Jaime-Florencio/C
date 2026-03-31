# 🔧 Bitwise em C para Sistemas Embarcados (Guia Prático Completo)

> Guia direto ao ponto para uso real em firmware (ESP32, AVR, etc)

---

# 📌 1. O que é bitwise?

Operações feitas diretamente nos bits (0 e 1).

Você usa isso quando:

* Manipula registradores
* Controla GPIO
* Trabalha com protocolos
* Precisa de performance

---

# ⚙️ 2. Operadores essenciais

| Operador | Nome        | Função           |            |
| -------- | ----------- | ---------------- | ---------- |
| `&`      | AND         | limpar bits      |            |
| `        | `           | OR               | ligar bits |
| `^`      | XOR         | inverter bits    |            |
| `~`      | NOT         | inverter tudo    |            |
| `<<`     | shift left  | multiplica por 2 |            |
| `>>`     | shift right | divide por 2     |            |

---

# 🧠 3. Padrões que você VAI usar

## ✅ Setar (ligar) um bit

```c
reg |= (1 << n);
```

---

## ❌ Limpar (desligar) um bit

```c
reg &= ~(1 << n);
```

---

## 🔁 Alternar (toggle)

```c
reg ^= (1 << n);
```

---

## 🔍 Ler um bit

```c
if (reg & (1 << n))
```

---

# 🧱 4. Exemplo real (GPIO)

```c
#define LED 5

GPIO_OUT_REG |= (1 << LED);   // liga
GPIO_OUT_REG &= ~(1 << LED);  // desliga
```

---

# 🧪 5. Máscara de bits (conceito chave)

Máscara = padrão usado pra mexer em bits específicos.

```c
reg &= 0xF0;
```

👉 Mantém apenas os 4 bits mais altos

---

# 🔗 6. Combinar bits (OR)

```c
byte = parte1 | parte2;
```

👉 Junta dois conjuntos de bits

---

# 🔄 7. Inverter bits específicos (XOR)

```c
reg ^= 0x04;
```

👉 Inverte apenas o bit 2

---

# 📦 8. Bit Fields (estrutura)

```c
struct {
    unsigned b0 : 1;
    unsigned b1 : 1;
    unsigned b2 : 1;
    unsigned b3 : 1;
    unsigned b4 : 1;
    unsigned b5 : 1;
    unsigned b6 : 1;
    unsigned b7 : 1;
} reg;
```

Uso:

```c
reg.b0 = 1;
reg.b6 = 1;
```

---

# ⚠️ 9. CUIDADO com Bit Fields

✔️ Use quando:

* Simular registradores
* Organizar dados

❌ Evite quando:

* Código crítico (depende do compilador)

---

# 🔥 10. Regra de ouro

❌ ERRADO:

```c
PORTB = 0x08;
```

✔️ CERTO:

```c
PORTB |= (1 << 3);
```

👉 Não destrói outros bits

---

# 🧠 11. Mentalidade de firmware

Você não está programando alto nível.

Você está:
👉 Controlando hardware bit a bit

---

# 📌 12. Resumo rápido

| Ação         | Código             |             |
| ------------ | ------------------ | ----------- |
| Setar bit    | `reg               | = (1 << n)` |
| Limpar bit   | `reg &= ~(1 << n)` |             |
| Ler bit      | `reg & (1 << n)`   |             |
| Inverter bit | `reg ^= (1 << n)`  |             |

---

# 🚀 13. Biblioteca auxiliar (PRONTO PRA USAR)

```c
#ifndef BIT_UTILS_H
#define BIT_UTILS_H

#define BIT_SET(reg, n)    ((reg) |= (1 << (n)))
#define BIT_CLEAR(reg, n)  ((reg) &= ~(1 << (n)))
#define BIT_TOGGLE(reg, n) ((reg) ^= (1 << (n)))
#define BIT_READ(reg, n)   ((reg) & (1 << (n)))

#endif
```

---

# 🧪 14. Exemplo com biblioteca

```c
#include "bit_utils.h"

BIT_SET(PORTB, 3);
BIT_CLEAR(PORTB, 3);

if (BIT_READ(PORTB, 3)) {
    // faz algo
}
```

---

# 🧠 15. Aplicação real (embarcados)

Você usa isso em:

* GPIO
* Registradores
* Drivers
* Comunicação (SPI, I2C, UART)
* Protocolos binários

---

# 📚 16. Base teórica

Este guia foi baseado no material do curso de C do Wagner Rambo (operações bit a bit e campos de bits), reorganizado de forma prática para uso em firmware.

---

# 🧠 Dica final (importante)

Se você domina isso, você sai de:

👉 "programador comum"

para:

🔥 "engenheiro de firmware de verdade"

---

# ✍️ Autor

Jaime Florencio
Engenharia Elétrica — Sistemas Embarcados

---
