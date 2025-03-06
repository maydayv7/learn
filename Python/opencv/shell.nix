with (import <nixpkgs> {}); let
  python = let
    packageOverrides = self: super: {
      opencv4 = super.opencv4.override {
        enableGtk2 = true;
        gtk2 = pkgs.gnome2.gtk;
      };
    };
  in
    python3.override {
      inherit packageOverrides;
      self = python;
    };
in
  mkShell {
    packages = [
      python3
      (python.withPackages (p: [
        p.pip
        p.autopep8

        p.numpy
        p.pandas
        p.matplotlib
        p.opencv4
      ]))
    ];
  }
