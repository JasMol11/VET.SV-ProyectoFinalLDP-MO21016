# 🐾 VET.SV - Sistema de Gestión Clínica Veterinaria 🐾

Este sistema fue desarrollado como parte del proyecto final de la asignatura **Lógica de Progrmación**. Tiene como propósito modernizar la gestión de la clínica veterinaria **VET.SV**, permitiendo el control centralizado de pacientes (mascotas), sus dueños, tratamientos y citas médicas.

---

## 👨‍💻 Autor

**Jason Alexander Molina Ortiz**  
Carnet: MO21016  
Carrera: Ingeniería en Desarrollo de Software  
Universidad de El Salvador

---

## 🛠️ Tecnologías y Herramientas Utilizadas

- **Lenguaje:** C++
- **Paradigmas:** Programación Orientada a Objetos (POO) + Manejo de Archivos Binarios
- **Entorno de ejecución:** Consola (modo texto)
- **Librerías estándar utilizadas:** `<iostream>`, `<fstream>`, `<cstring>`, `<iomanip>`
- **Editor recomendado:** Visual Studio Code

---

## 📁 Estructura del Proyecto

    VET.SV-ProyectoFinalLDP/
    │
    ├── .vscode/ # Configuraciones de VSCode (compilación, ejecución)
    │ ├── tasks.json
    │ └── c_cpp_properties.json
    │ └── settings.json
    │
    ├── data/ # Archivos binarios con datos persistentes
    │ ├── patients.bin
    │ ├── owners.bin
    │ ├── appointments.bin
    │ └── treatments.bin
    │
    ├── src/
    │ ├── main.cpp # Punto de entrada del sistema
    │
    │ ├── entities/ # Clases base del sistema
    │ │ ├── patient.{h,cpp}
    │ │ ├── owner.{h,cpp}
    │ │ ├── treatment.{h,cpp}
    │ │ └── appointment.{h,cpp}
    │
    │ └── managers/ # Módulos de gestión para cada entidad
    │ ├── managePatients.{h,cpp}
    │ ├── manageOwners.{h,cpp}
    │ ├── manageTreatments.{h,cpp}
    │ ├── manageAppointments.{h,cpp}
    │ └── manageReports.{h,cpp}
    │
    │ ├── tests/ # Archivos con datos de prueba (precarga de información)
    │ │ ├── testData.h
    │ │ ├── testData.cpp
    │ │ ├── loadData.cpp
    │
    └── readme.md

---

## ⚙️ Instrucciones de Compilación y Ejecución

1. Abre el proyecto en **Visual Studio Code**
2. Presiona `Shift + Ctrl + P` (ó `Shift + Cmd + P` en Mac) y selecciona `Tasks: Run Task`
3. Ejecuta el task de precarga de datos (`Cargar datos de prueba`)
4. Luego, ejecuta el task principal (`Compilar y ejecutar app`)

> Asegúrate de tener instalado un compilador de C++ y las extensiones de C/C++ de Microsoft para VSCode

---

## 🎮 Funcionalidades del Sistema

Al iniciar el programa, se despliega el **menú principal** con las siguientes opciones:

1. Gestión de Pacientes  
2. Gestión de Dueños  
3. Gestión de Tratamientos  
4. Gestión de Citas  
5. Gestión de Reportes  
0. Salir

**Cada Módulo incluye Funcionalidades como:**

- ➕ Agregar nuevos registros  
- 🔍 Buscar registros existentes  
- ✏️ Editar información  
- 🔁 Navegación dinámica dentro del módulo  

Los datos se almacenan y gestionan mediante archivos binarios para mayor eficiencia y persistencia

---

## 📆 Validaciones Implementadas

- **Formato de fechas:** `DD-MM-AAAA`
- **Formato de horas:** `HH:MM`, con intervalos de 30 minutos
- **Restricción de duplicados:** No se permiten citas duplicadas en el mismo horario
- **Cadenas:** Se manejan con `char[]` para compatibilidad con archivos binarios

---

## 📊 Reportes Disponibles

- 📄 Listado de todos los dueños y pacientes
- 🗓️ Citas por día y por dueño
- 💉 Tratamientos asignados por paciente


Los reportes se muestran directamente por consola y pueden exportarse o expandirse en futuras versiones

---

## 💡 Posibles mejoras futuras

- Interfaz gráfica con Qt o una aplicación web
- Exportación de reportes a PDF o CSV
- Sistema de autenticación para roles de usuario (recepcionista, veterinario, admin)
- Notificaciones o recordatorios automáticos para citas

---

## 🎓 Contexto académico

Este proyecto fue desarrollado como parte del trabajo final de la asignatura **Diseño y Programación de Base de Datos**, en la **Universidad de El Salvador**

---


## ✅ Estado del proyecto

✅ Funcionalidad completa en consola  
✅ Persistencia de datos con archivos binarios  
✅ Validación básica implementada  
✅ Preparado para ampliaciones futuras

---

¡Gracias por visitar este repositorio! Si deseas contribuir o tienes sugerencias, no dudes en abrir un issue o un pull request 🐶 🐾
