#include <ntddk.h>

// makes paimon fly out of your screen
// and transport paimon to the real world
// beside you, of course
extern "C" {
    VOID DriverUnload(_In_ PDRIVER_OBJECT DriverObject) {
        UNREFERENCED_PARAMETER(DriverObject);
        DbgPrint("Paimon unloaded\n");
    }

    NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {
        UNREFERENCED_PARAMETER(RegistryPath);

        DriverObject->DriverUnload = DriverUnload;
        DbgPrint("Paimon loaded\n");

        KIRQL oldIrql;
        KeRaiseIrql(DISPATCH_LEVEL, &oldIrql);

        volatile int* PAIMON = nullptr;
        int EMERGENCY_FOOD = *PAIMON;

        KeLowerIrql(oldIrql);

        return STATUS_SUCCESS;
    }
}
// In all seriousness, don't fucking run random code you see on the internet, including this one.