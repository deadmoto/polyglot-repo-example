import io.grpc.ServerBuilder;
import io.grpc.stub.StreamObserver;
import proto.EchoProto.EchoRequest;
import proto.EchoProto.EchoResponse;
import proto.EchoServiceGrpc.EchoServiceImplBase;

import java.io.IOException;

public class EchoServer {

    public static void main(String[] args) throws IOException, InterruptedException {
        ServerBuilder.forPort(54321)
                .addService(new EchoService())
                .build()
                .start()
                .awaitTermination();
    }

    private static class EchoService extends EchoServiceImplBase {
        @Override
        public void echo(EchoRequest request, StreamObserver<EchoResponse> responseObserver) {
            System.err.println("Received: " + request.getText());
            responseObserver.onNext(EchoResponse.newBuilder()
                    .setText(request.getText())
                    .build());
            responseObserver.onCompleted();
        }
    }
}
