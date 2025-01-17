ARG CUDA_VERSION=12.4.1
ARG IMAGE_DISTRO=ubuntu22.04

FROM nvidia/cuda:${CUDA_VERSION}-devel-${IMAGE_DISTRO} AS builder

WORKDIR /build_gpu_burn
COPY ./gpu_burn /build_gpu_burn
RUN make

WORKDIR /build_p2pBandwidthLatencyTest
COPY ./p2pBandwidthLatencyTest /build_p2pBandwidthLatencyTest
RUN make

WORKDIR /build_cublas
COPY ./cublas /build_cublas
RUN make

FROM nvidia/cuda:${CUDA_VERSION}-runtime-${IMAGE_DISTRO}

COPY --from=builder /build_gpu_burn/gpu_burn /app/
COPY --from=builder /build_gpu_burn/compare.ptx /app/
COPY --from=builder /build_p2pBandwidthLatencyTest/p2pBandwidthLatencyTest /app/
COPY --from=builder /build_cublas/cublas /app/


WORKDIR /app

CMD ["./gpu_burn", "60"]
