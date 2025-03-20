container: Dockerfile
	docker build -t pico .

run: container
	docker run --mount type=bind,src=$(CURDIR),dst=/build -it pico bash
