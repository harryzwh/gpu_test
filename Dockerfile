ARG CUDA_VERSION=11.8.0
ARG IMAGE_DISTRO=ubi8

FROM nvidia/cuda:${CUDA_VERSION}-devel-${IMAGE_DISTRO} AS builder

WORKDIR /build_gpu_burn
COPY ./gpu_burn /build_gpu_burn
RUN make

WORKDIR /build_p2pBandwidthLatencyTest
COPY ./p2pBandwidthLatencyTest /build_p2pBandwidthLatencyTest
RUN make

FROM nvidia/cuda:${CUDA_VERSION}-runtime-${IMAGE_DISTRO}

COPY --from=builder /build_gpu_burn/gpu_burn /app/
COPY --from=builder /build_gpu_burn/compare.ptx /app/
COPY --from=builder /build_p2pBandwidthLatencyTest/p2pBandwidthLatencyTest /app/


WORKDIR /app

CMD ["./gpu_burn", "60"]
