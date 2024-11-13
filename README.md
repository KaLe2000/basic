# Учу C

### Компиляция
`gcc program.c -o program`
Для компиляции с дебагом через gdb к gcc необходимо добавить флаг -g
`gcc program.c -o program -g`
`gdb program`

example для дебага:
`
list // просмотр кода
break 35 // строка, точка останова
delete 1 // удаление первой точки останова
run // выполнение в режиме дебага
continue // переход к следующей точке останова/следующей итерации
print value // вывод значения переменной на момент выполнения
`

### Запуск
`./program`

### todo
- Писать тесты 