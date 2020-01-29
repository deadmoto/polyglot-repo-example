package main

import (
	"context"
	"log"
	"time"

	"google.golang.org/grpc"

	"echo"
)

func main() {
	conn, err := grpc.Dial("localhost:54321", grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		log.Fatalf("could not connect: %v", err)
	}
	defer conn.Close()

	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	c := echo.NewEchoServiceClient(conn)
	r, err := c.Echo(ctx, &echo.EchoRequest{Text: "Hello world!"})
	if err != nil {
		log.Fatalf("request failed: %v", err)
	}
	println(r.Text)
}
