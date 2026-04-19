# REPORT

## Laboratory work VI

В репозитории выполнено продолжение проекта из `lab05` и добавлена конфигурация пакетирования через `CPack`.

## Что сделано

1. Перенесен проект из `lab05`.
2. Добавлено версионирование проекта.
3. Создан файл `CPackConfig.cmake`.
4. Добавлены:
   - `DESCRIPTION`
   - `ChangeLog.md`
5. Настроена установка приложения `solver`.
6. В репозиторий включены `TASK.md` и `REPORT.md`.

## Проверка

```bash
cmake -S . -B _build
cmake --build _build
ctest --test-dir _build --output-on-failure
cmake --build _build --target package
```

## Ссылки

- Репозиторий: `https://github.com/kanadya07/lab06`
- Задание: `TASK.md`
