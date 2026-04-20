# Отчет по лабораторной работе №6

## Тема работы

Изучение средств пакетирования с помощью CPack.

## Цель работы

Познакомиться с настройкой пакетирования проекта и оформить необходимые файлы
для создания пакета.

## Ход работы

### 1. Подготовка проекта

Сначала я использовала проект из лабораторной работы №5 и на его основе
создала репозиторий `lab06`.

Команды:

```bash
git clone https://github.com/kanadya07/lab05.git lab06
cd lab06
git remote remove origin
git remote add origin https://github.com/kanadya07/lab06.git
```

### 2. Добавление версии проекта

Потом в основной файл `CMakeLists.txt` я добавила информацию о версии проекта.

### 3. Создание файлов для CPack

Дальше были созданы файлы, которые нужны для пакетирования:

1. `CPackConfig.cmake`
2. `DESCRIPTION`
3. `ChangeLog.md`

Пример команд:

```bash
touch CPackConfig.cmake
touch DESCRIPTION
touch ChangeLog.md
```

### 4. Подключение пакетирования

После этого я добавила подключение `CPack` в проект и настроила установку
приложения `solver`.

### 5. Проверка сборки и пакетирования

Для проверки можно использовать такие команды:

```bash
cmake -S . -B _build
cmake --build _build
ctest --test-dir _build --output-on-failure
cmake --build _build --target package
```

### 6. Добавление отчета и задания

В конце я добавила в репозиторий задание и отчет.

```bash
git add TASK.md REPORT.md
git commit -m "Добавила задание и отчет"
git push origin master
```

## Что находится в репозитории

1. `TASK.md`
2. `REPORT.md`
3. `CPackConfig.cmake`
4. `DESCRIPTION`
5. `ChangeLog.md`
6. проект из предыдущих лабораторных работ

## Вывод

Во время выполнения этой лабораторной работы я познакомилась с тем, как можно
подготавливать проект не только к сборке, но и к пакетированию.

## Ссылка на репозиторий

https://github.com/kanadya07/lab06
