## Homework

### Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
	Создал репрезиторий.

2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.
	```
	cd workspace/projects/lab02
	git remote add origin https://github.com/ammobaggage/lab02.git
	```
3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
	```
	touch hello_world.cpp
	nano hello_world.cpp
	```
4. Добавьте этот файл в локальную копию репозитория.
	```
	git add .
	```
5. Закоммитьте изменения с *осмысленным* сообщением.
	```
	git commit -m "Первая версия программы"
	git push origin main
	
	```
6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.
	```
	nano hello_world.cpp
	
	```
7. Закоммитьте новую версию программы.
	```
	git add .
	git commit -m "Улучшен код программы"
	```
8. Запуште изменения в удалёный репозиторий.
	```
	git push origin main
	```
9. Проверьте, что история коммитов доступна в удалёный репозитории.
	Проверил и убедился, что все коммиты видно.

### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. В локальной копии репозитория создайте локальную ветку `patch1`.
	```
	git branch patch1
	git checkout patch1
	```
2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
	```
	nano hello_world.cpp
 	git commit -am "Патч для программы. Теперь хороший стиль кода"
	git push origin patch1
	```
4. Проверьте, что ветка `patch1` доступна в удалёный репозитории.

	pic 1![1](https://github.com/user-attachments/assets/8fa77ce1-1ed9-49d1-8e27-0b24c77af689)

5. Создайте pull-request `patch1 -> master`.

	pic 2![2](https://github.com/user-attachments/assets/474af57f-a363-4b83-9c02-8ee960173e98)

6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
	```
	nano hello_world.cpp
	```

7. **commit**, **push**.
	```
	git commit -am "Создан pull request и добавлен комментарий в код."
	git push origin patch1
	```
8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request

	pic 3![3](https://github.com/user-attachments/assets/c0e6d4f7-15d0-4b44-8529-9fbbb2e65d66)

	pic 3.1![3 1](https://github.com/user-attachments/assets/c21dccde-1006-499d-b6f3-72e978845cfd)

9. В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.

	pic 4![4](https://github.com/user-attachments/assets/2ad1132b-b40b-49c1-bf7a-01c92d8b3e9a)

10. Локально выполните **pull**.	
	```
	git pull origin main
	```
11. С помощью команды **git log** просмотрите историю в локальной версии ветки `main`.

[Вывод](https://gist.github.com/ammobaggage/cbcb299939737e8b9034ef8574debdfa)

12. Удалите локальную ветку `patch1`.

	pic 5![5](https://github.com/user-attachments/assets/43314b40-ed95-4dc1-944d-f6559d219cf6)
	```
	git branch -d patch1
	git fetch --prune
	```

### Part III

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. Создайте новую локальную ветку `patch2`.
	```
	git pull origin main
	git branch patch2
	git checkout patch2
	```
2. Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.
	```
	clang-format -style=Mozilla -i hello_world.cpp
	```
3. **commit**, **push**, создайте pull-request `patch2 -> master`.
	```
	git commit -am "Добавлен код стайл Mozilla"
	git push origin patch2
	pic 6![6](https://github.com/user-attachments/assets/95560a56-2c6b-4e0d-8129-eed9af062f0c)

	```
4. В ветке **main** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
	`Изменил`
5. Убедитесь, что в pull-request появились *конфликтны*.

	pic 7![7](https://github.com/user-attachments/assets/fc629c51-7f68-4c92-98a5-8fe00b59f7e7)

6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.
	```
	git pull --rebase origin main
	nano hello_world.cpp
	git rebase --continue	
	```
7. Сделайте *force push* в ветку `patch2`
	```
	git push origin patch2 --force-with-lease
	```
8. Убедитель, что в pull-request пропали конфликты.

	pic 8![8](https://github.com/user-attachments/assets/0e20f545-744b-4af2-a748-e6a65546728c)
 
9. Вмержите pull-request `patch2 -> master`.

   	pic 9![9](https://github.com/user-attachments/assets/da33248b-9ac2-4b43-a122-356862284df8)


##UPD

Я не увидел, что накосячил с кодом, поэтому в самом конце добавил нормальную компилируемую версию.
