/*
Dependiendo de tu sistema operativo actual, el comportamiento de la
función calloc puede diferir de lo descrito en su página del manual.
Debes seguir la siguiente regla: Si nmemb o size es 0, entonces
calloc() debe devolver un puntero único que pueda pasarse con éxito a
free().

SYNOPSIS
     #include <stdlib.h>

     void *calloc(size_t count, size_t size);

     void free(void *ptr);

     void *malloc(size_t size);

DESCRIPTION
     The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
     allocate memory.  The allocated memory is aligned such that it can be used
     for any data type, including AltiVec- and SSE-related types.

     The free() function frees allocations that were created via the preceding
     allocation functions.
     The free() function deallocates the memory allocation pointed to by ptr. If
     ptr is a NULL pointer, no operation is performed.

     The malloc() function allocates size bytes of memory and returns a pointer
     to the allocated memory.

     The calloc() function contiguously allocates enough space for count objects
     that are size bytes of memory each and returns a pointer to the allocated
     memory.  The allocated memory is filled with bytes of value zero.

RETURN VALUES
     If successful, calloc() & malloc() functions return a pointer to allocated memory.  If there
     is an error, they return a NULL pointer and set errno to ENOMEM.

     The free() function does not return a value.

Para DEBUGGING ALLOCATION ERRORS ir a man malloc

Te lo explico **como corrector de 42**, corto pero riguroso, centrándonos en *qué hacen de verdad* y *qué errores te suspenden*.

---

## 1. `malloc` — reserva memoria **sin inicializar**

### Prototipo

void *malloc(size_t size);

### Qué hace

* Pide al **heap** un bloque de `size` bytes.
* Devuelve un **puntero al primer byte** del bloque.
* **NO inicializa** la memoria → el contenido es **indeterminado**.
* Si falla, devuelve `NULL`.

### Consecuencias reales

* Leer memoria devuelta por `malloc` **antes de escribirla** ⇒ **comportamiento indefinido**.
* El tipo del puntero lo decides tú al hacer el cast:

  int *p = malloc(10 * sizeof(int));

* La memoria vive **hasta que llames a `free()`**.

### Errores típicos (42 ⚠️)

* Olvidar comprobar `NULL`.
* Usar `sizeof(ptr)` en vez de `sizeof(*ptr)`.
* No liberar → **leak = KO**.
* Asumir que está a cero → **falso**.

---

## 2. `calloc` — reserva memoria **inicializada a 0**

### Prototipo

void *calloc(size_t nmemb, size_t size);

### Qué hace

* Reserva `nmemb * size` bytes.
* **Inicializa todos los bytes a 0**.
* Devuelve un puntero al bloque.
* Si falla, devuelve `NULL`.

### Diferencia clave con `malloc`

malloc(100);        // basura
calloc(100, 1);     // todo a 0

Esto es **crítico** para:

* strings (`'\0'`)
* arrays de punteros (`NULL`)
* structs con flags

---

## 3. Regla ESPECIAL de 42 sobre `calloc` (MUY IMPORTANTE)

En libft **NO sigues exactamente el man**.

> Si `nmemb == 0` o `size == 0`
> 👉 **debe devolver un puntero válido que pueda pasarse a `free()`**

Eso significa:

* **NO devolver `NULL`**
* Aunque el tamaño total sea 0

Muchos suspensos vienen de aquí.

---

## 4. Internamente (modelo mental)

No necesitas saber cómo lo implementa el sistema, pero sí esto:

* El heap es una zona dinámica.
* `malloc/calloc` gestionan metadatos ocultos.
* Tú **solo** ves el puntero al bloque útil.
* Es ilegal:

  * hacer `free()` dos veces
  * hacer `free()` de algo no reservado
  * escribir fuera del bloque

---

## 5. Relación con libft

En libft:

* `ft_strdup` → usa `malloc`
* `ft_calloc` → normalmente:

  * llama a `malloc`
  * luego a `ft_bzero` o `memset`

Pero cuidado:

* **overflow**: `nmemb * size` puede desbordar `size_t`

  * corrector exigente lo mira

---

## 6. Resumen rápido (examen)

| Función | Inicializa | Tamaño       | Caso 0                     |
| ------- | ---------- | ------------ | -------------------------- |
| malloc  | ❌ no       | bytes        | indefinido                 |
| calloc  | ✅ sí (0)   | nmemb × size | **puntero liberable (42)** |

---

>>> Usar esto al compilar: 
cc -Wall -Werror -Wextra ft_calloc.c ft_bzero.c 

*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int	main(void)
{
	int	*ptr_a;
	int	*ptr_b;
	size_t	count;
	size_t	i;

	count = 10;
	ptr_a = ft_calloc(count, sizeof(*ptr_a));
	ptr_b = calloc(count, sizeof(*ptr_b));
	if (!ptr_a || !ptr_b)
		return (1);
	i = 0;
	while (i < count)
	{
		if (ptr_a[i] != 0 || ptr_b[i] != 0)
		{
			printf("Error! No inicializada a 0!\n");
			free(ptr_a);
			free(ptr_b);
			return (1);
		}
		i++;
	}
	printf("OK!!\n");
	free(ptr_a);
	free(ptr_b);
	return (0);
}
*/
