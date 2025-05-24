#include "fluent_icons.h"
#include "MainWindow.h"
#include <AUI/Util/UIBuildingHelpers.h>
#include <AUI/Platform/APlatform.h>
#include <AUI/View/ADrawableView.h>
#include <AUI/View/ASlider.h>
#include <range/v3/all.hpp>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/AButton.h>
#include <AUI/Platform/APlatform.h>
#include <AUI/View/ADrawableView.h>
#include <AUI/View/AProgressBar.h>
#include <AUI/View/ASpacerFixed.h>
#include <AUI/View/AScrollArea.h>
#include <AUI/View/ASpinnerV2.h>
#include <AUI/View/AText.h>
// #include <AUI/Audio/IAudioPlayer.h>

#include <range/v3/action/sort.hpp>
#include <AUI/Platform/AMessageBox.h>
// #include <AUI/Audio/ABadFormatException.h>

using namespace declarative;

struct Song {
    AString title;
};

struct State {
    AVector<_<Song>> songs;
};

static _<AView> playlistView(){
    return Centered::Expanding {Label { "hui" },};

    // State& state
    // return AScrollArea::Builder().
    //     withContents(
    //     AUI_DECLARATIVE_FOR(i, state.songs,  AVerticalLayout) {
    //         return Label { i->title };
    //     }
    // );
}

static _<AView> playerView(){
    return Centered::Expanding{
        Vertical {
            Centered{
                _new<AView>() with_style {
                    FixedSize{160_dp},
                    BackgroundSolid{AColor::GRAY},
                    BorderRadius{4_dp},
                    BoxShadow{0, 4_dp, 32_dp, AColor::BLACK.transparentize(0.7f) },
                },
            },

            SpacerFixed { 16_dp },

            _new<ASlider>(),
            Horizontal{
                Label {"0:00"} with_style { ATextAlign::CENTER},
                SpacerExpanding{},
                Label {"0:00"} with_style { ATextAlign::CENTER},
            },

            SpacerFixed { 16_dp },

            Label { "Title" } with_style { ATextAlign::CENTER, FontSize(14_pt)},
            Label { "Author" } with_style { ATextAlign::CENTER, FontSize(10_pt)},
            Label { "Label" } with_style { ATextAlign::CENTER, FontSize(10_pt)},

            SpacerFixed { 16_dp },

            Centered {
                Horizontal {
                    Label { fluent_icons::ic_fluent_previous_48_filled } with_style {
                        Font { ":img/FluentSystemIcons-Filled.ttf" },
                        FontSize { 32_dp },
                    },
                    Label { fluent_icons::ic_fluent_play_circle_48_filled } with_style {
                        Font { ":img/FluentSystemIcons-Filled.ttf" },
                        FontSize { 48_dp },
                    },
                    Label { fluent_icons::ic_fluent_next_48_filled } with_style {
                        Font { ":img/FluentSystemIcons-Filled.ttf" },
                        FontSize { 32_dp },
                    },
                } with_style { LayoutSpacing { 8_dp } },
            },

        }
    };
}

MainWindow::MainWindow()
  : AWindow("Project template app", 800_dp, 600_dp) {

    setExtraStylesheet(AStylesheet{
        {
            t<AView>(),
            TextColor { AColor::WHITE},
        },
    });

    setContents(Centered {
        Horizontal::Expanding{
            playlistView(),
            playerView(),
        }
    } with_style {
        BackgroundSolid { 0x333333_rgb },
    });   
}

