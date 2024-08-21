typedef struct Region {
    PVOID mbase;
    std::size_t msize;
}
typedef struct _MEM_INFO {
    PVOID pBase; 
    DWORD rSize;
    DWORD rShasum;
} MEM_INFO, *_MEM_INFO;

static auto memoryBook = std::vector < std::shared_ptr <MEM_INFO> > ();

void TrackRegion(Region region) {
    auto RegionCheksum = "0000"; // TODO
    for (const auto & pCurrRegion : memoryBook) {
        if (pCurrRegion->pBase == region.mbase) {
            auto _ = std::make_shared<MEM_INFO>();
            _.pBase = region.mbase;
            _.rSize = region.msize;
            _.rShasum = RegionCheksum;
            memoryBook.push_back(_);
            return;
        }
    }
}

void ReleaseRegion(Region region) {
    for (const auto & pCurrRegion : memoryBook) {
        if (pCurrRegion->pBase == region.mbase) {
            memoryBook.erase(pCurrRegion);
            return;
        }
    }
}

void tick() {
    return;
}